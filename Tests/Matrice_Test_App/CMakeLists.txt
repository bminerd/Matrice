cmake_minimum_required (VERSION 2.6)
project (Matrice_Test_App C CXX ASM)

set(PLAT4M_CORE_DIR ${PROJECT_SOURCE_DIR}/../../Dependencies/Plat4m_Core/Plat4m_Core)

set(PROJECT_FLAGS "-g \
                   -pthread \
                   -Wall \
                   -Wno-comment \
                   -fsanitize=address")

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${PROJECT_FLAGS}")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${PROJECT_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PROJECT_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_FLAGS}")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../../)
include_directories(${PLAT4M_CORE_DIR}/../)

set(source_files ${PROJECT_SOURCE_DIR}/main.cpp
                 ${PROJECT_SOURCE_DIR}/ApplicationMatriceTest.cpp
                 ${PROJECT_SOURCE_DIR}/../MatrixTest.cpp
                 ${PROJECT_SOURCE_DIR}/../VectorTest.cpp
                 ${PROJECT_SOURCE_DIR}/../MatrixVectorTest.cpp
                 ${PROJECT_SOURCE_DIR}/../../Matrice/Matrice.cpp
                 ${PROJECT_SOURCE_DIR}/../../Matrice/Allocator.cpp
                 ${PLAT4M_CORE_DIR}/Application.cpp
                 ${PLAT4M_CORE_DIR}/Module.cpp
                 ${PLAT4M_CORE_DIR}/System.cpp
                 ${PLAT4M_CORE_DIR}/Processor.cpp
                 ${PLAT4M_CORE_DIR}/AllocationMemory.cpp
                 ${PLAT4M_CORE_DIR}/Thread.cpp
                 ${PLAT4M_CORE_DIR}/ThreadPolicy.cpp
                 ${PLAT4M_CORE_DIR}/ThreadPolicyManager.cpp
                 ${PLAT4M_CORE_DIR}/Mutex.cpp
                 ${PLAT4M_CORE_DIR}/MutexLock.cpp
                 ${PLAT4M_CORE_DIR}/WaitCondition.cpp
                 ${PLAT4M_CORE_DIR}/QueueDriver.cpp
                 ${PLAT4M_CORE_DIR}/Semaphore.cpp
                 ${PLAT4M_CORE_DIR}/Base.cpp
                 ${PLAT4M_CORE_DIR}/ErrorBase.cpp
                 ${PLAT4M_CORE_DIR}/ErrorManager.cpp
                 ${PLAT4M_CORE_DIR}/MemoryManager.cpp
                 ${PLAT4M_CORE_DIR}/UnitTest/ApplicationUnitTestApp.cpp
                 ${PLAT4M_CORE_DIR}/UnitTest/UnitTest.cpp
                 ${PLAT4M_CORE_DIR}/Linux/SystemLinux.cpp
                 ${PLAT4M_CORE_DIR}/Linux/ProcessorLinux.cpp
                 ${PLAT4M_CORE_DIR}/Posix/ThreadPosix.cpp
                 ${PLAT4M_CORE_DIR}/Posix/MutexPosix.cpp
                 ${PLAT4M_CORE_DIR}/Posix/WaitConditionPosix.cpp
                 ${PLAT4M_CORE_DIR}/Posix/QueueDriverPosix.cpp
                 ${PLAT4M_CORE_DIR}/Posix/SemaphorePosix.cpp
)

add_executable(${PROJECT_NAME} ${source_files})
target_link_libraries(${PROJECT_NAME} rt)
