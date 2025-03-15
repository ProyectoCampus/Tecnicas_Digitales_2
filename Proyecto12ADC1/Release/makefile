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
proyecto12ADC1.lss \

FLASH_IMAGE += \
proyecto12ADC1.hex \

EEPROM_IMAGE += \
proyecto12ADC1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto12ADC1.elf secondary-outputs

# Tool invocations
proyecto12ADC1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto12ADC1.map -mmcu=atmega128 -o "proyecto12ADC1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto12ADC1.lss: proyecto12ADC1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto12ADC1.elf  >"proyecto12ADC1.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto12ADC1.hex: proyecto12ADC1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto12ADC1.elf  "proyecto12ADC1.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto12ADC1.eep: proyecto12ADC1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto12ADC1.elf  "proyecto12ADC1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto12ADC1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto12ADC1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto12ADC1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
