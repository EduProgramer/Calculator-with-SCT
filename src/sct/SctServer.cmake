find_path(CPPREST_INCLUDE cpprest/http_client.h)
find_library(CPPREST_LIB NAMES cpprest_2_9d cpprest_2_9 cpprestd cpprest)
find_package(Boost REQUIRED COMPONENTS random system thread filesystem chrono atomic date_time regex)
find_package(OpenSSL 1.0.0 REQUIRED)

file(GLOB SCT_SERVER_SOURCES "./src/sct/*.cpp")
file(GLOB SCT_SERVER_HEADERS "./src/sct/*.hpp")

target_sources(${PROJECT_NAME} PUBLIC ${SCT_SERVER_SOURCES} ${SCT_SERVER_HEADERS})

target_link_libraries(${PROJECT_NAME}
  ${CPPREST_LIB}
  Boost::boost
  Boost::random
  Boost::system
  Boost::thread
  Boost::filesystem
  Boost::chrono
  Boost::atomic
  Boost::date_time
  Boost::regex
  OpenSSL::SSL
)
