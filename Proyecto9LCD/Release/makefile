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
proyecto9LCD.lss \

FLASH_IMAGE += \
proyecto9LCD.hex \

EEPROM_IMAGE += \
proyecto9LCD.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto9LCD.elf secondary-outputs

# Tool invocations
proyecto9LCD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto9LCD.map -mmcu=atmega128 -o "proyecto9LCD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto9LCD.lss: proyecto9LCD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto9LCD.elf  >"proyecto9LCD.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto9LCD.hex: proyecto9LCD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto9LCD.elf  "proyecto9LCD.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto9LCD.eep: proyecto9LCD.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto9LCD.elf  "proyecto9LCD.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto9LCD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto9LCD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto9LCD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
