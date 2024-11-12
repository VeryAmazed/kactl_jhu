set ic ts=4 sw=4 nu
im jk <esc>
no ; :
ca hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \| md5sum \| cut -c-6
