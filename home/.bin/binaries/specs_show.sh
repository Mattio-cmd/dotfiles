#!/bin/sh

# Script to display system information on Artix Linux

echo "### System Information ###"
echo "Kernel version:"
uname -a
echo ""

echo "### CPU Information ###"
cat /proc/cpuinfo
echo ""

echo "### Memory Information ###"
cat /proc/meminfo
echo ""

echo "### Motherboard Information ###"
sudo dmidecode -t baseboard
echo ""

echo "### BIOS Information ###"
sudo dmidecode -t bios
echo ""

echo "### Storage Drives Information ###"
sudo fdisk -l
echo ""

echo "### GPU Information ###"
lspci -v | grep -i vga
echo ""

echo "### Network Information ###"
ip addr
echo ""

#echo "### Installed Packages ###"
#pacman -Q
#echo ""

echo "### Filesystem Disk Space Usage ###"
df -h
echo ""

