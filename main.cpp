#include <cstdio>
#include <cstdlib>

#define SIZE_OUT (1<<12)
#define SIZE_INP (SIZE_OUT*8)

int main() {
    char buff_out[SIZE_OUT];
    char buff_inp[SIZE_INP];
    while( fread(buff_inp,SIZE_INP,1,stdin) == 1 ) {
        for( int i=0 ; i<SIZE_INP ; i++ ) {
            if( buff_inp[i] != '0' && buff_inp[i] != '1') {
                abort();
            }
            buff_out[i/8] <<= 1;
            buff_out[i/8] |= buff_inp[i] == '1';
        }
        if( fwrite(buff_out,SIZE_OUT,1,stdout) != 1 ) {
            abort();
        }
    }
    return 0;
}
