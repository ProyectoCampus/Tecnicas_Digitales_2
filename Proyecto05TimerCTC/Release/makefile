################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
proyecto5timerCTC.lss \

FLASH_IMAGE += \
proyecto5timerCTC.hex \

EEPROM_IMAGE += \
proyecto5timerCTC.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto5timerCTC.elf secondary-outputs

# Tool invocations
proyecto5timerCTC.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto5timerCTC.map -mmcu=atmega128 -o "proyecto5timerCTC.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto5timerCTC.lss: proyecto5timerCTC.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto5timerCTC.elf  >"proyecto5timerCTC.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto5timerCTC.hex: proyecto5timerCTC.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto5timerCTC.elf  "proyecto5timerCTC.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto5timerCTC.eep: proyecto5timerCTC.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto5timerCTC.elf  "proyecto5timerCTC.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto5timerCTC.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto5timerCTC.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto5timerCTC.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
