# Sofa.Components.Topology
- Remove RadiusContainer (from SofaGeneralFEM) in EdgeToQuad

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

# Sofa.Components.LinearSolver
- Lots of modules needs LinearSolver just for *Matrix files (Sparse, etc) -> move to core ?