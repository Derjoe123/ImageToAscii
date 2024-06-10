#include <fstream>
#include <iostream>

#include "../lib/lodepng.h"
int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <input.png> <output.txt> <ratio> <characters (i|I...H#)>" << std::endl;
        return 1;
    }
    // reverse the characters to get a better result
    std::string allchars = ".'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$;|";
    unsigned char* image;
    unsigned width, height;
    unsigned error = lodepng_decode_file(&image, &width, &height, argv[1], LodePNGColorType::LCT_RGBA, 8);
    if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    std::ofstream outputAscii(argv[2]);
    double ratio = std::stod(argv[3]);
    std::string characters = (argc > 4) ? argv[4] : allchars;
    for (size_t i = 0; i < height - ratio; i += ratio) {
        for (size_t j = 0; j < width - ratio; j += ratio) {
            double sum = 0;
            for (size_t k = 0; k < ratio; k++) {
                for (size_t l = 0; l < ratio; l++) {
                    sum += image[(i + k) * width * 4 + (j + l) * 4];
                }
            }
            sum /= (ratio * ratio);
            outputAscii << characters[characters.size() - 1 - (sum / 255 * (characters.size() - 1))];
        }
        outputAscii << std::endl;
    }

    return 0;
}
