#include "hash.h"

#define d 256  // # of character
#define primeNo 13  // prime number


vector<int> search_pattern_hash(string text, string pattern){
    vector<int>result;

  int patternsize = pattern.size();
  int textSize = text.size();
  int i, j; //counters
  int patternHash = 0; //hash value for pattern
  int textHash = 0;  // hash value for text
  int h = 1;


  // to calculate h**(m-1)  --> h power (m-1)
  for (i = 0; i < patternsize - 1; i++)
    h = (h * d) % primeNo;

  // Calculate hash value for pattern and first window of the text
  for (i = 0; i < patternsize; i++) {
    patternHash = (d * patternHash + pattern[i]) % primeNo;

    textHash = (d * textHash + text[i]) % primeNo;
  }

  // Find the match
  // for illustration the outer for is to loop for the window inside the text of pattern size
  for (i = 0; i <= textSize - patternsize; i++) {
    if (patternHash == textHash) {
      for (j = 0; j < patternsize; j++) {
        if (text[i + j] != pattern[j])
          break;
      }
      // if the 2nd for loop reach the patternsize then the window and pattern are equal
      if (j == patternsize)
        result.push_back( i );
    }

    // for optimizing rabin Karb algorithm as the two neighboring elements in hash is very simillar
    // we can teduce the 2nd hash from the first hash by the formula below by removing the leading digit and add the later one.
    if (i < textSize - patternsize) {
      textHash = (d * (textHash - text[i] * h) + text[i + patternsize]) % primeNo;

      // the formula before may give negative value in order to avoid this add to it the prime no.
      if (textHash < 0)
        textHash = (textHash + primeNo);
    }
  }


  return result;
}

/*------------------------------------------------------

IN ORDER TO CHECK THE HASH ALGORITHM(RABIN-KARB)

-------------------------------------------------------*/
// int main(int argc, char **argv)
// {

//     string text = "dsfh kjadadfssfkjhadskjfh akjsdadfshfkjadshfkjasdfeidadfso adshkj fkjadshf kkjdadfsadsfah fkjladsf uaesbkjdfm, a";
//     string pattern = "dadfs";

//     // string text = "abcab", pattern = "ab";

//     vector<int> result1;
//     result1 = search_pattern_hash(text, pattern);

//     int size = result1.size();

//     for (int i = 0; i < size; i++)
//     {
//         cout << result1[i] << ", ";
//     }
//     return 0;
// }