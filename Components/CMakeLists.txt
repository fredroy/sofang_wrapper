cmake_minimum_required(VERSION 3.12)


add_subdirectory(LinearSolver)
add_subdirectory(ODESolver)
add_subdirectory(Topology)
add_subdirectory(PhysicalModel/Mass)
add_subdirectory(PhysicalModel/SolidMechanics/Elasticity/Springs)
add_subdirectory(PhysicalModel/SolidMechanics/Elasticity/FEM)
add_subdirectory(Constraint/Projective)
add_subdirectory(Constraint/Lagrangian) # Weird dep on Mass and Fem
add_subdirectory(AnimationLoop) # Needs LinearSolver, Constraint
add_subdirectory(Mapping)
add_subdirectory(Collision/Models)
add_subdirectory(Collision/Detection/Algorithm)
add_subdirectory(Collision/Detection/Intersection)
add_subdirectory(Container)
add_subdirectory(Collision/Response/Contact)
add_subdirectory(Engine)
add_subdirectory(Visual)
# add_subdirectory(Utils)
# add_subdirectory(Controller)
# add_subdirectory(Device)
# add_subdirectory(IO)