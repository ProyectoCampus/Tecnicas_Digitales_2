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
proyecto6FastPWM_Modif.lss \

FLASH_IMAGE += \
proyecto6FastPWM_Modif.hex \

EEPROM_IMAGE += \
proyecto6FastPWM_Modif.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: proyecto6FastPWM_Modif.elf secondary-outputs

# Tool invocations
proyecto6FastPWM_Modif.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,proyecto6FastPWM_Modif.map -mmcu=atmega128 -o "proyecto6FastPWM_Modif.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

proyecto6FastPWM_Modif.lss: proyecto6FastPWM_Modif.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S proyecto6FastPWM_Modif.elf  >"proyecto6FastPWM_Modif.lss"
	@echo 'Finished building: $@'
	@echo ' '

proyecto6FastPWM_Modif.hex: proyecto6FastPWM_Modif.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex proyecto6FastPWM_Modif.elf  "proyecto6FastPWM_Modif.hex"
	@echo 'Finished building: $@'
	@echo ' '

proyecto6FastPWM_Modif.eep: proyecto6FastPWM_Modif.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex proyecto6FastPWM_Modif.elf  "proyecto6FastPWM_Modif.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: proyecto6FastPWM_Modif.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega128 proyecto6FastPWM_Modif.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) proyecto6FastPWM_Modif.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
