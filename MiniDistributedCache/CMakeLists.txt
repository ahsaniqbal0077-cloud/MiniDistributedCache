add_executable(MiniDistributedCache

    # Main
    src/main.cpp

    # Interfaces
    include/ICache.h
    include/CacheItem.h
    include/CacheStats.h

    # Cache
    cache/LRUCache.h
    cache/LRUCache.cpp

    cache/LFUCache.h
    cache/LFUCache.cpp

    cache/FIFOCache.h
    cache/FIFOCache.cpp

    # Manager
    manager/CacheManager.h
    manager/CacheManager.cpp

    # Benchmark
    benchmark/Benchmark.h
    benchmark/Benchmark.cpp
    benchmark/WorkloadGenerator.h
    benchmark/WorkloadGenerator.cpp

    # Simulator
    simulator/DataGenerator.h
    simulator/DataGenerator.cpp

    # Tests
    tests/StressTest.h
    tests/StressTest.cpp

    network/TCPServer.h
    network/TCPServer.cpp

    network/TCPClient.h
    network/TCPClient.cpp
 "network/TCPServer.cpp" "network/TCPServer.h" "network/TCPClient.cpp" "network/TCPClient.h")