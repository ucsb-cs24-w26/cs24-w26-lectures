# Makefile for benchmarking find operations
# Targets: build, run, clean, plot

# Compiler and flags
CXX = g++
CXXFLAGS = --std=c++11 -O0
PYTHON = python3

# Source files
BENCHMARK_SRC = benchmarking_find.cpp
BENCHMARK_EXE = benchmark

# Output files
TIMING_OUTPUT = timing_results.txt

# Default target
.PHONY: all build run clean plot help

all: build run plot

# Build the benchmarking executable
build: $(BENCHMARK_EXE)

$(BENCHMARK_EXE): $(BENCHMARK_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<
	@echo "✓ Compiled benchmark executable"

# Run the benchmark
run: $(BENCHMARK_EXE)
	@echo "Running benchmarks..."
	@./$(BENCHMARK_EXE)

# Generate plots from the timing results
plot: $(TIMING_OUTPUT)
	@echo "Generating plots..."
	@$(PYTHON) data_plot_benchmarking.py
	@echo "✓ Plots displayed"

# Clean up generated files
clean:
	@rm -f $(BENCHMARK_EXE) $(TIMING_OUTPUT)
	@echo "✓ Cleaned up generated files"

# Help message
help:
	@echo "Usage: make [target]"
	@echo ""
	@echo "Targets:"
	@echo "  all    - Build, run benchmarks, and generate plots (default)"
	@echo "  build  - Compile the benchmark executable"
	@echo "  run    - Execute the benchmark and save timing results"
	@echo "  plot   - Generate plots from timing results"
	@echo "  clean  - Remove generated files"
	@echo "  help   - Display this help message"
