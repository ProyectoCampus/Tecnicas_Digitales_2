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
proyecto7disp7seg.lss \

FLASH_IMAGE += \
proyecto7disp7seg.hex \

EEPROM_IMAGE += \
proyecto7disp7seg.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto7disp7seg.elf secondary-outputs

# Tool invocations
proyecto7disp7seg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto7disp7seg.map -mmcu=atmega128 -o "proyecto7disp7seg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto7disp7seg.lss: proyecto7disp7seg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto7disp7seg.elf  >"proyecto7disp7seg.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto7disp7seg.hex: proyecto7disp7seg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto7disp7seg.elf  "proyecto7disp7seg.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto7disp7seg.eep: proyecto7disp7seg.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto7disp7seg.elf  "proyecto7disp7seg.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto7disp7seg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto7disp7seg.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto7disp7seg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
