#include <cmath>
#include <ostream>
#include <string>

#include "direct_problem"
#include "testing"


int main() {
    aiw::Vec<3> r0{0., 0., 3000.};
    double v0 = 2000., delta_v = 1000., sigma = 750.;
    Testing::VField v(r0, v0, delta_v, sigma);
    int rank = 2;
    double cone_rad = 7 * M_PI / 18;
    int N = 250;

    Logger::LoggerEdge logging;
    logging.init(N, "./tst", true);

    std::list<Data::Ray> rays;
    std::list<Data::Tube> tubes;
    Data::init_rays(rank, v0, cone_rad, rays, tubes);

    DirectProblem::DPSolver direct_problem{};
    direct_problem.init(0.02, N, true);
    direct_problem.run(rays, tubes, v, logging);

    return 0;
}
