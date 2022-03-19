# stub

make

mkdir -pv iso
cp -v kernel_fnix.elf limine.cfg ~/.local/bin/limine.sys ~/.local/bin/limine-cd.bin ~/.local/bin/limine-eltorito-efi.bin iso/


xorriso -as mkisofs -b limine-cd.bin \
        -no-emul-boot -boot-load-size 4 -boot-info-table \
        --efi-boot limine-eltorito-efi.bin \
        -efi-boot-part --efi-boot-image --protective-msdos-label \
        iso -o fnix.iso

~/.local/bin/limine-install fnix.iso


qemu-system-x86_64 fnix.iso -d int --no-reboot --enable-kvm -m 256M
# make clean
