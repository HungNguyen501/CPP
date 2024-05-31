ProjectName := Cpp-Core

CiScript := ci/ci.sh

RED := \033[1;31m
GREEN := \033[1;32m
BLUE := \033[0;34m
NO_COLOR := \033[0m

check_ref_name:
	@bash $(CiScript) validate_ref_name $(REF_TYPE) $(REF_NAME)

init:
	@cd configurations/ && cmake .
	@cd configurations/ && cmake --build . --target hello_world && ../bin/hello_world

clean:
	@cmake --build configurations/ --target clean

build:
	@cd configurations/ && cmake --build . --target $(t)

run:
	@./bin/$(t)

list:
	@echo "List of executable targets:"
	@echo "---------------------------"
	@sed -n 's/^add_executable(//p' configurations/CMakeLists.txt | awk -F' ' '{print $$1}'

test:
	@bash $(CiScript) run_tests

run_ci:
	@bash $(CiScript) run_ci $(CHANGES)
	# @bazel clean --async

.PHONY: help
all: help
help: Makefile
	@echo "Run 'make list' to show target list"
