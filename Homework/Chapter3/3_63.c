/*
 3.63?
 */
long switch_prob (long x, long n) {
    long result = x;
    switch (n) {
        case 60:
        case 62:
            result = 8 * x;
            break;
        case 63:
            result = x >> 3;
            break;
        case 64:
            result = (result << 4) - x;
            x = result;
        case 65:
            x = x * x;
        default:
            result = x + 0x4b;
    }
    return result;
}