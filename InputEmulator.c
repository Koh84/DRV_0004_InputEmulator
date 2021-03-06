
/* �ο�drivers\input\keyboard\gpio_keys.c */

#include <linux/module.h>
#include <linux/version.h>

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/input.h>


static struct input_dev *input_emulator_dev;

static int input_emulator_init(void)
{
	int i;
	
	/* 1. Allocate one input_dev structure */
	input_emulator_dev = input_allocate_device();

	/* 2. Settings */
	/* 2.1 What type of event can be generated */
	set_bit(EV_KEY, input_emulator_dev->evbit);
	set_bit(EV_REP, input_emulator_dev->evbit);
	
	/* 2.2 Can produce all type of keys from this event */
	for(i = 0; i<BITS_TO_LONGS(KEY_CNT); i++)
	{
		input_emulator_dev->keybit[i] = ~0UL;
	}

	/* create data for android */
	input_emulator_dev->name ="InputEmulatorFromKelvinKoh";
	input_emulator_dev->id.bustype = 1;
	input_emulator_dev->id.vendor = 0x1234;
	input_emulator_dev->id.product = 0x5678;
	input_emulator_dev->id.version = 1;

	/* 3. register */
	input_register_device(input_emulator_dev);
	
	return 0;
}

static void input_emulator_exit(void)
{
	input_unregister_device(input_emulator_dev);
	input_free_device(input_emulator_dev);	
}

module_init(input_emulator_init);

module_exit(input_emulator_exit);

MODULE_LICENSE("GPL");



