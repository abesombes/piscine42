#include <stdio.h>
#include <stdlib.h>

void hexdump(unsigned char *buffer, unsigned long index, unsigned long width)
{
    unsigned long i;
    for (i=0;i<index;i++)
    {
        printf("%02x ",buffer[i]);
    }
    for (unsigned long spacer=index;spacer<width;spacer++)
        printf("    ");
    printf(": ");
    for (i=0;i<index;i++)
    {
        if (buffer[i] < 32) printf(".");
        else printf("%c",buffer[i]);
    }
    printf("\n");
}

int hexdump_file(FILE *infile,unsigned long start, unsigned long stop, unsigned long width)
{
    char ch;
    unsigned long f_index=0;
    unsigned long bb_index=0;
    unsigned char *byte_buffer = malloc(width);
    if (byte_buffer == NULL)
    {
        printf("Could not allocate memory for byte_buffer\n");
        return -1;
    }
    while (!feof(infile))
    {
        ch = getc(infile);  
        if ((f_index >= start)&&(f_index <= stop))
        {
            byte_buffer[bb_index] = ch;
            bb_index++;
        }
        if (bb_index >= width)
        {
            hexdump(byte_buffer,bb_index,width);
            bb_index=0;
        }   
        f_index++;  
    }
    if (bb_index)
        hexdump(byte_buffer,bb_index,width);
    fclose(infile);
    free(byte_buffer);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: hexdump <infile> <start> <end> <width>\n");
        return 0;
    }
    FILE *infile=fopen(argv[1],"rb");
    if (infile==(FILE *)NULL)
    {
        printf("Error opening input file %s\n",argv[1]);
        return 0;
    }
    printf("Filename: \"%s\"\n",   argv[1]);
    printf("Start : %lu\n",  atoi(argv[2]));
    printf("End    : %lu\n",   atoi(argv[3]));
    printf("Bytes per Line: %lu\n",atoi(argv[4]));  
    int result = hexdump_file(infile,atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
    return 0;
}
