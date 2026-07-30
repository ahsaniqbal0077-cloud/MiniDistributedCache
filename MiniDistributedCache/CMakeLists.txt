# CMakeList.txt : CMake project for MiniDistributedCache, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (MiniDistributedCache "src/main.cpp"  "include/ICache.h" "include/CacheItem.h" "include/CacheStats.h" "cache/LRUCache.h" "cache/LRUCache.cpp" "simulator/DataGenerator.h" "simulator/DataGenerator.cpp" "manager/CacheManager.h" "manager/CacheManager.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MiniDistributedCache PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
