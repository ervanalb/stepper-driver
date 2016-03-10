#include "sine.h"
#include "hw.h"

#define LIMIT PWM_PERIOD

const float sine_table[256] = {
    LIMIT * 0.00000, LIMIT * 0.00614, LIMIT * 0.01227, LIMIT * 0.01841, LIMIT * 0.02454, LIMIT * 0.03067, LIMIT * 0.03681, LIMIT * 0.04294,
    LIMIT * 0.04907, LIMIT * 0.05520, LIMIT * 0.06132, LIMIT * 0.06744, LIMIT * 0.07356, LIMIT * 0.07968, LIMIT * 0.08580, LIMIT * 0.09191,
    LIMIT * 0.09802, LIMIT * 0.10412, LIMIT * 0.11022, LIMIT * 0.11632, LIMIT * 0.12241, LIMIT * 0.12850, LIMIT * 0.13458, LIMIT * 0.14066,
    LIMIT * 0.14673, LIMIT * 0.15280, LIMIT * 0.15886, LIMIT * 0.16491, LIMIT * 0.17096, LIMIT * 0.17700, LIMIT * 0.18304, LIMIT * 0.18907,
    LIMIT * 0.19509, LIMIT * 0.20110, LIMIT * 0.20711, LIMIT * 0.21311, LIMIT * 0.21910, LIMIT * 0.22508, LIMIT * 0.23106, LIMIT * 0.23702,
    LIMIT * 0.24298, LIMIT * 0.24893, LIMIT * 0.25487, LIMIT * 0.26079, LIMIT * 0.26671, LIMIT * 0.27262, LIMIT * 0.27852, LIMIT * 0.28441,
    LIMIT * 0.29028, LIMIT * 0.29615, LIMIT * 0.30201, LIMIT * 0.30785, LIMIT * 0.31368, LIMIT * 0.31950, LIMIT * 0.32531, LIMIT * 0.33111,
    LIMIT * 0.33689, LIMIT * 0.34266, LIMIT * 0.34842, LIMIT * 0.35416, LIMIT * 0.35990, LIMIT * 0.36561, LIMIT * 0.37132, LIMIT * 0.37701,
    LIMIT * 0.38268, LIMIT * 0.38835, LIMIT * 0.39399, LIMIT * 0.39962, LIMIT * 0.40524, LIMIT * 0.41084, LIMIT * 0.41643, LIMIT * 0.42200,
    LIMIT * 0.42756, LIMIT * 0.43309, LIMIT * 0.43862, LIMIT * 0.44412, LIMIT * 0.44961, LIMIT * 0.45508, LIMIT * 0.46054, LIMIT * 0.46598,
    LIMIT * 0.47140, LIMIT * 0.47680, LIMIT * 0.48218, LIMIT * 0.48755, LIMIT * 0.49290, LIMIT * 0.49823, LIMIT * 0.50354, LIMIT * 0.50883,
    LIMIT * 0.51410, LIMIT * 0.51936, LIMIT * 0.52459, LIMIT * 0.52980, LIMIT * 0.53500, LIMIT * 0.54017, LIMIT * 0.54532, LIMIT * 0.55046,
    LIMIT * 0.55557, LIMIT * 0.56066, LIMIT * 0.56573, LIMIT * 0.57078, LIMIT * 0.57581, LIMIT * 0.58081, LIMIT * 0.58580, LIMIT * 0.59076,
    LIMIT * 0.59570, LIMIT * 0.60062, LIMIT * 0.60551, LIMIT * 0.61038, LIMIT * 0.61523, LIMIT * 0.62006, LIMIT * 0.62486, LIMIT * 0.62964,
    LIMIT * 0.63439, LIMIT * 0.63912, LIMIT * 0.64383, LIMIT * 0.64851, LIMIT * 0.65317, LIMIT * 0.65781, LIMIT * 0.66242, LIMIT * 0.66700,
    LIMIT * 0.67156, LIMIT * 0.67609, LIMIT * 0.68060, LIMIT * 0.68508, LIMIT * 0.68954, LIMIT * 0.69397, LIMIT * 0.69838, LIMIT * 0.70275,
    LIMIT * 0.70711, LIMIT * 0.71143, LIMIT * 0.71573, LIMIT * 0.72000, LIMIT * 0.72425, LIMIT * 0.72846, LIMIT * 0.73265, LIMIT * 0.73682,
    LIMIT * 0.74095, LIMIT * 0.74506, LIMIT * 0.74914, LIMIT * 0.75319, LIMIT * 0.75721, LIMIT * 0.76120, LIMIT * 0.76517, LIMIT * 0.76910,
    LIMIT * 0.77301, LIMIT * 0.77689, LIMIT * 0.78074, LIMIT * 0.78456, LIMIT * 0.78835, LIMIT * 0.79211, LIMIT * 0.79584, LIMIT * 0.79954,
    LIMIT * 0.80321, LIMIT * 0.80685, LIMIT * 0.81046, LIMIT * 0.81404, LIMIT * 0.81758, LIMIT * 0.82110, LIMIT * 0.82459, LIMIT * 0.82805,
    LIMIT * 0.83147, LIMIT * 0.83486, LIMIT * 0.83822, LIMIT * 0.84155, LIMIT * 0.84485, LIMIT * 0.84812, LIMIT * 0.85136, LIMIT * 0.85456,
    LIMIT * 0.85773, LIMIT * 0.86087, LIMIT * 0.86397, LIMIT * 0.86705, LIMIT * 0.87009, LIMIT * 0.87309, LIMIT * 0.87607, LIMIT * 0.87901,
    LIMIT * 0.88192, LIMIT * 0.88480, LIMIT * 0.88764, LIMIT * 0.89045, LIMIT * 0.89322, LIMIT * 0.89597, LIMIT * 0.89867, LIMIT * 0.90135,
    LIMIT * 0.90399, LIMIT * 0.90660, LIMIT * 0.90917, LIMIT * 0.91171, LIMIT * 0.91421, LIMIT * 0.91668, LIMIT * 0.91911, LIMIT * 0.92151,
    LIMIT * 0.92388, LIMIT * 0.92621, LIMIT * 0.92851, LIMIT * 0.93077, LIMIT * 0.93299, LIMIT * 0.93518, LIMIT * 0.93734, LIMIT * 0.93946,
    LIMIT * 0.94154, LIMIT * 0.94359, LIMIT * 0.94561, LIMIT * 0.94759, LIMIT * 0.94953, LIMIT * 0.95144, LIMIT * 0.95331, LIMIT * 0.95514,
    LIMIT * 0.95694, LIMIT * 0.95870, LIMIT * 0.96043, LIMIT * 0.96212, LIMIT * 0.96378, LIMIT * 0.96539, LIMIT * 0.96698, LIMIT * 0.96852,
    LIMIT * 0.97003, LIMIT * 0.97150, LIMIT * 0.97294, LIMIT * 0.97434, LIMIT * 0.97570, LIMIT * 0.97703, LIMIT * 0.97832, LIMIT * 0.97957,
    LIMIT * 0.98079, LIMIT * 0.98196, LIMIT * 0.98311, LIMIT * 0.98421, LIMIT * 0.98528, LIMIT * 0.98631, LIMIT * 0.98730, LIMIT * 0.98826,
    LIMIT * 0.98918, LIMIT * 0.99006, LIMIT * 0.99090, LIMIT * 0.99171, LIMIT * 0.99248, LIMIT * 0.99321, LIMIT * 0.99391, LIMIT * 0.99456,
    LIMIT * 0.99518, LIMIT * 0.99577, LIMIT * 0.99631, LIMIT * 0.99682, LIMIT * 0.99729, LIMIT * 0.99772, LIMIT * 0.99812, LIMIT * 0.99848,
    LIMIT * 0.99880, LIMIT * 0.99908, LIMIT * 0.99932, LIMIT * 0.99953, LIMIT * 0.99970, LIMIT * 0.99983, LIMIT * 0.99992, LIMIT * 0.99998
};

int16_t cosine(float t, float amp)
{
    float result;
    int16_t ix = (int32_t)(t * 1024) & 1023;

    if(ix < 256) {
        result = sine_table[255 - ix];
    } else if(ix < 512) {
        result = -sine_table[ix - 256];
    } else if(ix < 768) {
        result = -sine_table[767 - ix];
    } else {
        result = sine_table[ix - 768];
    }

    result *= amp;
    int32_t result_d = result;

    if(result_d > LIMIT) {
        result_d = LIMIT;
    } else if(result_d < -LIMIT) {
        result_d = -LIMIT;
    }
    return (int16_t)result_d;
}

int16_t sine(float t, float amp)
{
    float result;
    int16_t ix = (int32_t)(t * 1024) & 1023;

    if(ix < 256) {
        result = sine_table[ix];
    } else if(ix < 512) {
        result = sine_table[511 - ix];
    } else if(ix < 768) {
        result = -sine_table[ix - 512];
    } else {
        result = -sine_table[1023 - ix];
    }

    result *= amp;
    int32_t result_d = result;

    if(result_d > LIMIT) {
        result_d = LIMIT;
    } else if(result_d < -LIMIT) {
        result_d = -LIMIT;
    }
    return (int16_t)result_d;
}
