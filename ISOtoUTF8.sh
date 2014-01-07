#!/bin/bash
find . -name "*.h" -print -exec iconv --from-code=ISO-8859-15 --to-code=UTF-8 "{}" -o "{}" \;
find . -name "*.c" -print -exec iconv --from-code=ISO-8859-15 --to-code=UTF-8 "{}" -o "{}" \;