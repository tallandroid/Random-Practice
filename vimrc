if v:lang =~ "utf8$" || v:lang =~ "UTF-8$"
   set fileencodings=ucs-bom,utf-8,latin1
endif

set nocompatible	" Use Vim defaults (much better!)
set bs=indent,eol,start		" allow backspacing over everything in insert mode
set shiftwidth=4 tabstop=4 	" always set autoindenting on
"set backup		" keep a backup file
set viminfo='20,\"50	" read/write a .viminfo file, don't store more
			" than 50 lines of registers
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set expandtab
syntax on
set list listchars=tab:▷⋅,trail:⋅,nbsp:⋅
set statusline=%F%m%r%h%w\ [TYPE=%Y\ %{&ff}]\
\ [%l/%L\ (%p%%)
filetype plugin indent on
au FileType py set autoindent
au FileType py set smartindent
au FileType py set textwidth=79 " PEP-8 Friendly
filetype plugin on
"added by me "
let Tlist_WinWidth = 40
let Tlist_Exit_OnlyWindow = 1
autocmd FileType python set omnifunc=pythoncomplete#Complete
nnoremap <silent> <F12> :TlistToggle<CR>
set textwidth=79
set statusline=%2*%n\|%<%*%-.40F%2*\|\ %2*%M\ %3*%=%1*\ %1*%2.6l%2*x%1*%1.9(%c%V%)%2*[%1*%P%2*]%1*%2B
set number
"noremap <silent> <C-w><C-w> <A-w>
nnoremap <silent> <F2> :NERDTreeToggle<CR>

" Only do this part when compiled with support for autocommands
if has("autocmd")
augroup fedora
autocmd!
" In text files, always limit the width of text to 78 characters
" autocmd BufRead *.txt set tw=78
" When editing a file, always jump to the last cursor position
autocmd BufReadPost *
\ if line("'\"") > 0 && line ("'\"") <= line("$") |
  \   exe "normal! g'\"" |
  \ endif
  " don't write swapfile on most commonly used directories for NFS mounts or USB sticks
  autocmd BufNewFile,BufReadPre /media/*,/mnt/* set directory=~/tmp,/var/tmp,/tmp
  " start with spec file template
  autocmd BufNewFile *.spec 0r /usr/share/vim/vimfiles/template.spec
  augroup END
endif

if has("cscope") && filereadable("/usr/bin/cscope")
   set csprg=/usr/bin/cscope
   set csto=0
   set cst
   set nocsverb
   " add any database in current directory
   if filereadable("cscope.out")
      cs add cscope.out
   " else add database pointed to by environment
   elseif $CSCOPE_DB != ""
      cs add $CSCOPE_DB
   endif
   set csverb
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

filetype plugin on

if &term=="xterm"
     set t_Co=8
     set t_Sb=[4%dm
     set t_Sf=[3%dm
endif

" Don't wake up system with blinking cursor:
" http://www.linuxpowertop.org/known.php
let &guicursor = &guicursor . ",a:blinkon0"

"Quit NERDTree if is the last buffer
function! NERDTreeQuit()
      redir => buffersoutput
        silent buffers
          redir END
            let pattern = '^\s*\(\d\+\)\(.....\) "\(.*\)"\s\+line \(\d\+\)$'
              let windowfound = 0

                for bline in split(buffersoutput, "\n")
                        let m = matchlist(bline, pattern)

                            if (len(m) > 0)
                                      if (m[2] =~ '..a..')
                                                  let windowfound = 1
                                                        endif
                                                            endif
                                                              endfor

                                                                if (!windowfound)
                                                                        quitall
                                                                          endif
                                                                      endfunction
                                                                      autocmd WinEnter * call NERDTreeQuit()
