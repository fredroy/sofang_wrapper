#include <sofa/component/linearsolver/config.h>

#include <SofaBaseLinearSolver/MatrixLinearSolver.inl>
#include <SofaDenseSolver/NewMatMatrix.h>
#include <SofaDenseSolver/NewMatVector.h>

namespace sofa::component::linearsolver
{

}

namespace sofa::component::linearsolver
{
    // template specialization on specific matrix types
    template class SOFA_SOFADENSESOLVER_API MatrixLinearSolver< NewMatMatrix, NewMatVector >;
    template class SOFA_SOFADENSESOLVER_API MatrixLinearSolver< NewMatSymmetricMatrix, NewMatVector >;
    template class SOFA_SOFADENSESOLVER_API MatrixLinearSolver< NewMatBandMatrix, NewMatVector >;
    template class SOFA_SOFADENSESOLVER_API MatrixLinearSolver< NewMatSymmetricBandMatrix, NewMatVector >;

} // namespace sofa::component::linearsolver