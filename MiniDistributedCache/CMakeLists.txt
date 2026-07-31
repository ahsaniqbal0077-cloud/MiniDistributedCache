# ============================================
# Mini Distributed Cache
# CMake Project
# ============================================

# ============================================
# Executable
# ============================================

add_executable(MiniDistributedCache

    # ==========================
    # Main
    # ==========================
    src/main.cpp

    # ==========================
    # Interfaces
    # ==========================
    include/ICache.h
    include/CacheItem.h
    include/CacheStats.h

    # ==========================
    # Cache Algorithms
    # ==========================
    cache/LRUCache.h
    cache/LRUCache.cpp

    cache/LFUCache.h
    cache/LFUCache.cpp

    # cache/FIFOCache.h
    # cache/FIFOCache.cpp

    # ==========================
    # Manager
    # ==========================
    manager/CacheManager.h
    manager/CacheManager.cpp

    # ==========================
    # Simulator
    # ==========================
    simulator/DataGenerator.h
    simulator/DataGenerator.cpp

  "cache/FIFOCache.h" "cache/FIFOCache.cpp")

# ============================================
# C++ Standard
# ============================================

if(CMAKE_VERSION VERSION_GREATER 3.12)

    set_property(
        TARGET MiniDistributedCache
        PROPERTY CXX_STANDARD 20
    )

endif()

# ============================================
# Future Modules
# ============================================

# network/
# cluster/
# benchmark/
# dashboard/
# tests/