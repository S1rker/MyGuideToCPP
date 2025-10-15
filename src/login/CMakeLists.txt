cmake_minimum_required(VERSION 3.10)

project(login VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the executable from the single source file
add_executable(login login.cpp)

# By default, use the workspace's top-level `include/` folder for headers.
# Users can override these with -DMYSQL_INCLUDE_DIR and -DMYSQL_LIB_DIR when running CMake.
set(MYPROJECT_ROOT "${CMAKE_SOURCE_DIR}/../.." CACHE PATH "Root of the project (used to locate include/ and libs)")
set(MY_INCLUDE_DIR "${MYPROJECT_ROOT}/include" CACHE PATH "Top-level include directory")
set(MYSQL_INCLUDE_DIR "${MY_INCLUDE_DIR}/mysql/9.4.0_3/include/mysql" CACHE PATH "MySQL include dir (override if needed)")
set(MYSQL_LIB_DIR "${MY_INCLUDE_DIR}/mysql/9.4.0_3/lib" CACHE PATH "MySQL lib dir (override if needed)")
set(MYSQLPP_INCLUDE_DIR "${MY_INCLUDE_DIR}/mysql++/3.3.0_4/include/mysql++" CACHE PATH "mysql++ include dir (override if needed)")
set(MYSQLPP_LIB_DIR "${MY_INCLUDE_DIR}/mysql++/3.3.0_4/lib" CACHE PATH "mysql++ lib dir (override if needed)")

# Add include directories so headers in include/ are visible to targets
target_include_directories(login PUBLIC
    ${MY_INCLUDE_DIR}
    ${MYSQL_INCLUDE_DIR}
    ${MYSQLPP_INCLUDE_DIR}
)

# Helper: prefer mysql++ if available, otherwise link directly to libmysqlclient.
find_library(MYSQLPP_LIB NAMES mysqlpp PATHS ${MYSQLPP_LIB_DIR} NO_DEFAULT_PATH)
find_library(MYSQLCLIENT_LIB NAMES mysqlclient libmysqlclient PATHS ${MYSQL_LIB_DIR} NO_DEFAULT_PATH)

if(MYSQLPP_LIB)
    message(STATUS "Linking against mysql++: ${MYSQLPP_LIB}")
    target_link_libraries(login PRIVATE ${MYSQLPP_LIB})
elseif(MYSQLCLIENT_LIB)
    message(STATUS "Linking against libmysqlclient: ${MYSQLCLIENT_LIB}")
    target_link_libraries(login PRIVATE ${MYSQLCLIENT_LIB})
else()
    message(WARNING "No mysql++ or libmysqlclient library found in provided lib dirs. You may need to install them or set MYSQL_LIB_DIR / MYSQLPP_LIB_DIR to point to them.")
endif()

# Allow users to pass additional linker dirs if needed
link_directories(${MYSQL_LIB_DIR} ${MYSQLPP_LIB_DIR})

# Install rule (optional)
install(TARGETS login RUNTIME DESTINATION bin)
