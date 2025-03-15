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
proyecto6FastPWM.lss \

FLASH_IMAGE += \
proyecto6FastPWM.hex \

EEPROM_IMAGE += \
proyecto6FastPWM.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto6FastPWM.elf secondary-outputs

# Tool invocations
proyecto6FastPWM.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto6FastPWM.map -mmcu=atmega128 -o "proyecto6FastPWM.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto6FastPWM.lss: proyecto6FastPWM.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto6FastPWM.elf  >"proyecto6FastPWM.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto6FastPWM.hex: proyecto6FastPWM.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto6FastPWM.elf  "proyecto6FastPWM.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto6FastPWM.eep: proyecto6FastPWM.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto6FastPWM.elf  "proyecto6FastPWM.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto6FastPWM.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto6FastPWM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto6FastPWM.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
