cmake_minimum_required (VERSION 2.6)
project (Matrice_Test_App C CXX ASM)

set(PLAT4M_CORE_DIR ${PROJECT_SOURCE_DIR}/../../Dependencies/Plat4m_Core/Plat4m_Core)

set(PROJECT_FLAGS "-g3 \
                   -pthread \
                   -fdebug-prefix-map=/home/matrice_sq=. \
                   -fdebug-prefix-map=${PROJECT_BINARY_DIR}=.")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${PROJECT_FLAGS}")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${PROJECT_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PROJECT_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_FLAGS}")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../../)
include_directories(${PLAT4M_CORE_DIR}/../)

set(source_files main.cpp
                 ApplicationMatriceTest.cpp
                 ${PROJECT_SOURCE_DIR}/../MatrixTest.cpp
                 ${PROJECT_SOURCE_DIR}/../VectorTest.cpp
                 ${PROJECT_SOURCE_DIR}/../MatrixVectorTest.cpp
                 ${PLAT4M_CORE_DIR}/Application.cpp
                 ${PLAT4M_CORE_DIR}/Module.cpp
                 ${PLAT4M_CORE_DIR}/System.cpp
                 ${PLAT4M_CORE_DIR}/Processor.cpp
                 ${PLAT4M_CORE_DIR}/AllocationMemory.cpp
                 ${PLAT4M_CORE_DIR}/Thread.cpp
                 ${PLAT4M_CORE_DIR}/Mutex.cpp
                 ${PLAT4M_CORE_DIR}/MutexLock.cpp
                 ${PLAT4M_CORE_DIR}/WaitCondition.cpp
                 ${PLAT4M_CORE_DIR}/QueueDriver.cpp
                 ${PLAT4M_CORE_DIR}/UnitTest/ApplicationUnitTestApp.cpp
                 ${PLAT4M_CORE_DIR}/UnitTest/UnitTest.cpp
                 ${PLAT4M_CORE_DIR}/Linux/SystemLinux.cpp
                 ${PLAT4M_CORE_DIR}/Linux/ProcessorLinux.cpp
                 ${PLAT4M_CORE_DIR}/Linux/ThreadLinux.cpp
                 ${PLAT4M_CORE_DIR}/Linux/MutexLinux.cpp
                 ${PLAT4M_CORE_DIR}/Linux/WaitConditionLinux.cpp
                 ${PLAT4M_CORE_DIR}/Linux/QueueDriverLinux.cpp)

include(CTest)

add_executable(Matrice_Test_App ${source_files})
add_test(Matrice_Test_App Matrice_Test_App)
set_tests_properties(Matrice_Test_App PROPERTIES
                     FAIL_REGULAR_EXPRESSION ".*FAIL.*")
