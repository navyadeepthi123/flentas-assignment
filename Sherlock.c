#include <stdio.h>
#include <string.h>

int main()
{
    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        char pattern[1001], text[100001];
        scanf("%s", pattern);
        scanf("%s", text);

        int patternCount[26] = {0};
        int textCount[26] = {0};
        int patternLen = strlen(pattern);
        int textLen = strlen(text);
        for (int i = 0; i < patternLen; i++)
        {
            patternCount[pattern[i] - 'a']++;
        }
        for (int i = 0; i < patternLen; i++)
        {
            textCount[text[i] - 'a']++;
        }
        int found = 0;
        for (int i = patternLen; i <= textLen; i++)
        {
            int match = 1;
            for (int j = 0; j < 26; j++)
            {
                if (patternCount[j] != textCount[j])
                {
                    match = 0;
                    break;
                }
            }
            if (match)
            {
                found = 1;
                printf("YES\n");
                break;
            }
            if (i < textLen)
            {
                textCount[text[i - patternLen] - 'a']--;
                textCount[text[i] - 'a']++;
            }
        }
        if (!found)
        {
            printf("NO\n");
        }
    }

    return 0;
}