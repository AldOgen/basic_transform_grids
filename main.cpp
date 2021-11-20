#include <cmath>
#include <ostream>
#include <string>
#include <filesystem>
#include <cstring>
#include <iostream>

#include "./scr/include/direct_problem"
#include "./scr/include/testing"
#include "./scr/unit_tests/grad_test"

int main(int argc, char* argv[]) {
    int rank = 2;
    double cone_rad = 7 * M_PI / 18;
    int N = 250;

    std::list<Data::Ray> rays;
    std::list<Data::Tube> tubes;

    if (argc == 2 && std::strcmp(argv[1], "unittest") == 0) {
        double v0 = 500., b = -10;
        std::array<double, 10> norm_dn0{
            0.001, 0.00129155, 0.0016681, 0.00215443, 0.00278256, 0.00359381, 0.00464159, 0.00599484, 0.00774264, 0.01
        };
        //UnitTests::TestVFieldConst v(v0);
        UnitTests::TestVFieldLinear v(v0, b);
        UnitTests::LoggerGrad logging;
        logging.init(N, "../tests/test_grad_lin");
        Data::init_rays(rank, v0, cone_rad, rays, tubes);
        UnitTests::GradTest grad_test{};
        grad_test.init(0.02, N, norm_dn0);
        grad_test.run(rays, v, logging);
    } else {
        aiw::Vec<3> r0{0., 0., 3000.};
        double v0 = 2000., delta_v = 1000., sigma = 750.;
        Testing::VField v(r0, v0, delta_v, sigma);
        Logger::LoggerN logging;
        logging.init(N, "../tests/test_n", true);
        Data::init_rays(rank, v0, cone_rad, rays, tubes);
        DirectProblem::DPSolver direct_problem{};
        direct_problem.init(0.02, N, true);
        direct_problem.run(rays, tubes, v, logging);
    }

    return 0;
}
