cmake_minimum_required(VERSION 3.12)


add_subdirectory(LinearSolver)
add_subdirectory(ODESolver)
add_subdirectory(Topology)
add_subdirectory(PhysicalModel/Mass)
add_subdirectory(PhysicalModel/SolidMechanics/Elasticity/Springs)
# add_subdirectory(Constraint)
# add_subdirectory(AnimationLoop) # Needs LinearSolver, Constraint
# add_subdirectory(Utils)
# add_subdirectory(Collision)
# add_subdirectory(Container)
# add_subdirectory(Controller)
# add_subdirectory(Engine)
# add_subdirectory(Mapping)
# add_subdirectory(Visual)
# add_subdirectory(Device)
# add_subdirectory(IO)