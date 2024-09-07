mkdir -p build
cd build

../configure --prefix=/usr/local/gcc-custom --disable-bootstrap --enable-languages=c,c++ || { echo "Configuration failed"; exit 1; }

make -j$(nproc) || { echo "Compilation failed"; exit 1; }

sudo make install || { echo "Installation failed"; exit 1; }

/usr/local/gcc-custom/bin/gcc ../test_program.c -o test_program || { echo "Test program compilation failed"; exit 1; }

./test_program || { echo "Test program failed"l exit 1; }

