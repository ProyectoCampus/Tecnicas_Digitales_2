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
proyecto1GPIO.lss \

FLASH_IMAGE += \
proyecto1GPIO.hex \

EEPROM_IMAGE += \
proyecto1GPIO.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto1GPIO.elf secondary-outputs

# Tool invocations
proyecto1GPIO.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto1GPIO.map -mmcu=atmega128 -o "proyecto1GPIO.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto1GPIO.lss: proyecto1GPIO.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto1GPIO.elf  >"proyecto1GPIO.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto1GPIO.hex: proyecto1GPIO.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto1GPIO.elf  "proyecto1GPIO.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto1GPIO.eep: proyecto1GPIO.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto1GPIO.elf  "proyecto1GPIO.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto1GPIO.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto1GPIO.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto1GPIO.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
