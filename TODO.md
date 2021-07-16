# Sofa.Components.Topology
- remove MechanicalObj dep on DynamicSparseGridGeometryAlgorithms

# Sofa.Components.Constraint.Lagrangian
- Remove use of UniformMass from UncoupledConstraintCorrection
- dont forget some of the collision related stuff from SofaConstraint

# Sofa.Components.Constraint.Projective
- dont forget some of the ff stuff from SofaBoundaryCondition

# Sofa.Components.blabla.FEM
- dont forget the nonFEM from GeneralFem

# Sofa.Components.AnimationLoop
- dont forget the mapping(?) from GeneralAnimationLoop
- Should FreeMotionAnimationLoop instanciate a GenericConstraintSolver instead of LCPCS ?

# Sofa.Components.LinearSolver
- Lots of modules needs LinearSolver just for \*Matrix files (Sparse, etc) -> move to core ?
- RotationMatrix in SofaCore includes something SofaBaseLinearSolver!

# Sofa.Components.Collision
- remove useless headers in SofaMeshCollision
- refactor LMDFilters
- remove RigidMapping dep from LocalMinDistanceFilter ?
- move RayTriangleIntersection utility class into helper ?

# Sofa.Components.Engine
- Distance engine has a weird dep on 

# Sofa.Components.IO.Mesh
- Grid creator mesh... is this more an engine ? to merge with the CreateGrid engine ?

# Sofa.Components.GUI.Core
- Remove or move InteractingBehaviorModel to ExternalBM ?
- Remove boost:program_options dep
