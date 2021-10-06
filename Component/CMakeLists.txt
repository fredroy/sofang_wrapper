cmake_minimum_required(VERSION 3.12)


add_subdirectory(Utils)
add_subdirectory(ODESolver)
add_subdirectory(LinearSolver)
add_subdirectory(Topology)
add_subdirectory(PhysicalModel)
add_subdirectory(Constraint)
add_subdirectory(AnimationLoop) # Needs Constraint
add_subdirectory(Mapping)
add_subdirectory(Container)
add_subdirectory(Collision)
add_subdirectory(Engine)
add_subdirectory(Visual)
add_subdirectory(IO)
# # add_subdirectory(Device)

add_subdirectory(GUI/Core)
add_subdirectory(Controller)
