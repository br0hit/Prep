__global__ void kernel(int *input)
{
    input[0] = input[0] * 100;
}

int main()
{
    int val = 2;
    printf("%d",val);
    kernel<<<1,1>>>(&val);
    printf("%d\n",val);
    return 0;
}