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
proyecto10LCDGrafico.lss \

FLASH_IMAGE += \
proyecto10LCDGrafico.hex \

EEPROM_IMAGE += \
proyecto10LCDGrafico.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto10LCDGrafico.elf secondary-outputs

# Tool invocations
proyecto10LCDGrafico.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto10LCDGrafico.map -mmcu=atmega128 -o "proyecto10LCDGrafico.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto10LCDGrafico.lss: proyecto10LCDGrafico.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto10LCDGrafico.elf  >"proyecto10LCDGrafico.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto10LCDGrafico.hex: proyecto10LCDGrafico.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto10LCDGrafico.elf  "proyecto10LCDGrafico.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto10LCDGrafico.eep: proyecto10LCDGrafico.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto10LCDGrafico.elf  "proyecto10LCDGrafico.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto10LCDGrafico.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto10LCDGrafico.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto10LCDGrafico.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
