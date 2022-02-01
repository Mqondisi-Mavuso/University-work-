char *replace(char *source, char const *pattern, char const *replacement)
{
    char *substring;
    static char *last_source;
    static char *last_replacement;
    int isNull = 0;

    if(source != NULL && (substring = strstr(source, pattern)) == NULL) {
        source = last_source;
        return source;
    }

    if(source == NULL) {
        source = last_source;
        isNull = 1;
        substring = strstr(last_replacement, pattern);
        if(substring == NULL) {
            return source;
        }
    }
    int pattern_len     = strlen(pattern);
    int replacement_len = strlen(replacement);
    int tail_len        = strlen(substring) + 1;
    last_replacement    = substring + replacement_len - 1;

    memcpy(substring + replacement_len, substring + pattern_len, tail_len * sizeof(char));

    memcpy(substring, replacement, replacement_len * sizeof(char));

    if(isNull == 0) {
        last_source = source;
    }

    return source;
}
