# Sofa.Components.Topology
- Remove RadiusContainer (from SofaGeneralFEM) in EdgeToQuad
- remove MechanicalObj dep on DynamicSparseGridGeometryAlgorithms

# Sofa.Components.Constraint.Lagrangian
- Remove use of UniformMass from UncoupledConstraintCorrection
- dont forget some of the collision related stuff from SofaConstraint

# Sofa.Components.Constraint.Projective
- dont forget some of the ff stuff from SofaBoundaryCondition

# Sofa.Components.blabla.FEM
- Try to remove the {Poisson/Radius/...}Container
- dont forget the nonFEM from GeneralFem

# Sofa.Components.AnimationLoop
- dont forget the mapping(?) from GeneralAnimationLoop

# Sofa.Components.LinearSolver
- SofaPreconditioner contains PrecondWarpConditioner, which needs weirdily TetraFem

# Sofa.Components.Collision
- remove useless headers in SofaMeshCollision
- refactor LMDFilters
- remove RigidMapping dep from LocalMinDistanceFilter ?
- move RayTriangleIntersection utility class into helper ?
- move OBB/Intr* things

# Sofa.Components.Engine
- Distance engine has a weird dep on 
- remove dep on IdentityMapping for GenerateGrid (because of helper::eq.... 🤨)

# Sofa.Components.LinearSolver
- Lots of modules needs LinearSolver just for \*Matrix files (Sparse, etc) -> move to core ?


# Sofa.Components.IO.Mesh
- Grid creator mesh... is this more an engine ? to merge with the CreateGrid engine ?

# Sofa.Components.GUI.Core
- Remove or move InteractingBehaviorModel to ExternalBM ?
- Remove boost:program_options dep