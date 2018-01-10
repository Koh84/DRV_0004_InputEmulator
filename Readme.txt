make all

copy to nfs_root

insmod InputEmulator.ko

"1"
sendevent /dev/input/event5 1 2 1
sendevent /dev/input/event5 1 2 0
sendevent /dev/input/event5 0 0 0

"2"
sendevent /dev/input/event5 1 3 1
sendevent /dev/input/event5 1 3 0
sendevent /dev/input/event5 0 0 0

