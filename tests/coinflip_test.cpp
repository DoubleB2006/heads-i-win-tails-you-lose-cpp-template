#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/coinflip.hpp"

TEST_CASE("coin flip simulation runs without throwing") {
    // Just make sure the simulation completes successfully.
    REQUIRE_NOTHROW(runCoinFlipSimulation());
}

TEST_CASE("benchmarking the coin flip simulation") {
    BENCHMARK("runCoinFlipSimulation()") {
       runCoinFlipSimulation();
        return 0;
    };
}
