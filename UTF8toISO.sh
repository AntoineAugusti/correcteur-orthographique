#!/bin/bash
find . -name "*.h" -print -exec iconv --from-code=UTF-8 --to-code=ISO-8859-15 "{}" -o "{}" \;
find . -name "*.c" -print -exec iconv --from-code=UTF-8 --to-code=ISO-8859-15 "{}" -o "{}" \;