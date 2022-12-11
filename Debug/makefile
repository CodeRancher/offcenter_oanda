################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include oanda_v20/test/src/subdir.mk
-include oanda_v20/src/transaction/subdir.mk
-include oanda_v20/src/trade/subdir.mk
-include oanda_v20/src/response/subdir.mk
-include oanda_v20/src/request/subdir.mk
-include oanda_v20/src/primitives/subdir.mk
-include oanda_v20/src/pricing/subdir.mk
-include oanda_v20/src/position/subdir.mk
-include oanda_v20/src/order/subdir.mk
-include oanda_v20/src/json/subdir.mk
-include oanda_v20/src/instrument/subdir.mk
-include oanda_v20/src/endpoint/subdir.mk
-include oanda_v20/src/common/subdir.mk
-include oanda_v20/src/account/subdir.mk
-include examples/src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := offcenter_oanda
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: offcenter_oanda

# Tool invocations
offcenter_oanda: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "offcenter_oanda" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) offcenter_oanda
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
