# Created by newuser for 5.8
EDITOR='nvim'
export _JAVA_AWT_WM_NONREPARENTING=1 # for android studio in dwm
export XDG_DATA_HOME=$HOME/.local/share
export XDG_CONFIG_HOME=$HOME/.config
export XDG_STATE_HOME=$HOME/.local/state
export XDG_CACHE_HOME=$HOME/.cache/

export CARGO_HOME="$XDG_DATA_HOME"/cargo
export RUSTUP_HOME="$XDG_DATA_HOME"/.rustup
export CUDA_CACHE_PATH="$XDG_CACHE_HOME"/nv
export GNUPGHOME="$XDG_DATA_HOME"/.gnupg
export GRADLE_USER_HOME="$XDG_DATA_HOME"/.gradle
export ICEAUTHORITY="$XDG_CACHE_HOME"/.ICEauthority
export NODE_REPL_HISTORY="$XDG_DATA_HOME"/.node_repl_history
export _JAVA_OPTIONS=-Djava.util.prefs.userRoot="$XDG_CONFIG_HOME"/java
export WORKON_HOME="$XDG_DATA_HOME/virtualenvs"
export PASSWORD_STORE_DIR="$XDG_DATA_HOME"/.pass
export WINEPREFIX="$XDG_DATA_HOME"/.wine
#export XINITRC="$XDG_CONFIG_HOME"/X11/.xinitrc
#export XAUTHORITY="$XDG_STATE_HOME"/.Xauthority

alias monerod=monerod --data-dir "$XDG_DATA_HOME"/.bitmonero
alias dosbox=dosbox -conf "$XDG_CONFIG_HOME"/.dosbox/dosbox.conf
alias "nvidia-settings --config"="$XDG_CONFIG_HOME"/nvidia/settings
alias wget=wget --hsts-file="$XDG_DATA_HOME/wget-hsts"

export TERM="xterm-256color"                      # getting proper colors

################
##    PATH    ##
################
export PATH=$PATH:~/.local/share/flutter/bin
export PATH=$PATH:~/.pub-cache/bin
export PATH=$PATH:~/.local/bin
export PATH=$PATH:/usr/lib/dart/bin
export PATH=$PATH:/home/mattio/.local/share/cargo/bin

export HISTORY_IGNORE="(ls|cd|pwd|exit|sudo reboot|history|cd -|cd ..)"
export STARSHIP_CONFIG=~/.config/starship.toml

##################
##    Aliases   ##
##################
alias ls='exa --header'
alias ll='exa -l --header'
alias la='exa -l  -a --header'

#alias ls='lsd'
#alias ll='lsd -l'
#alias la='lsd -l  -a'
alias tree='exa -T'
alias ctree='treefetch -xmas'
alias aquarium='asciiquarium'
alias batterperc='cat /sys/class/power_supply/BAT1/capacity'
alias cat='bat --theme gruvbox-dark'
alias du='dust'
alias df='duf'
alias haxorman='unimatrix -s 96 -c green'
alias "dmki"='doas make clean install'
alias gits='git status'
alias gitp='git push'
alias gita='git add'
alias gitco='git commit'
alias gitcl='git clone'
alias weather='curl wttr.in'
alias py='python'
alias fa='falion'
alias e='exit'
alias shutdown='doas shutdown -h now'
alias reboot='doas reboot'
alias heroic='prime-run heroic'
alias mpv='mpv --keep-open'
alias mov='cd /media/games/movies'
alias rdr2='light -S 100; killall picom; killall themechnger.sh; killall breakreminder.sh; killall java; xrandr -s 1280x720; steam'
alias lunarc='prime-run ~/Downloads/lunarclient/lunarclient'
alias v='nvim'
alias cr='cargo run'
alias sx='startx'
alias minecraft-run='prime-run java -jar /home/mattio/Downloads/mc/TLauncher-2.83.jar'
alias pacfetch='neofetch --ascii_distro PacBSD'
alias gentoo='strat -r gentoo'
alias emerge='strat -r gentoo emerge'
alias gneofetch='strat -r gentoo neofetch'
alias "cd gentoo"='cd /bedrock/strata/gentoo/home/mattio'
alias "pallet-gruv"='sxiv Downloads/colorscheme/gruvbox_pallet.png'
alias "movies-now"='cd $HOME/videos/movies'
alias "shred"='shred -f -z -n 3'
alias rm="rm -i"
alias 'rm -rf'="rm -rf -i"
alias cc="tcc"
alias localip="ip route get 1 | awk '{print $7}'"
alias wp-show="sxiv /media/games/backups/wallpapers/wallpapers"
alias "xmr-mine"='./xmrig -o gulf.moneroocean.stream:10128 -u 4AdqumQrDrnRFqkK2tKyW6PXdDwPCtyEC4R98jAMU6Ho53kcy8aRVMbHMgpiW1V9XpDdWj4qHkjJ6FFvBHqd7sTK7raCtCU -p artgreen'
alias "xmr-mine-support"='./xmrig --coin=XMR --donate-level=0% --cpu-max-threads-hint 100 -o pool.supportxmr.com:3333 -u 4AdqumQrDrnRFqkK2tKyW6PXdDwPCtyEC4R98jAMU6Ho53kcy8aRVMbHMgpiW1V9XpDdWj4qHkjJ6FFvBHqd7sTK7raCtCU -p artgreen'
#alias "v-project"='cd code_projects/js/DooT; nvim App.tsx src/components/animated-checkbox.tsx src/screens/main.tsx'
#alias "xmr-mine-support"='./xmrig -o  -u 4AdqumQrDrnRFqkK2tKyW6PXdDwPCtyEC4R98jAMU6Ho53kcy8aRVMbHMgpiW1V9XpDdWj4qHkjJ6FFvBHqd7sTK7raCtCU -p artgreen'

#For ytdl
alias ytmp3='yt-dlp -ciw -o "%(title)s.%(ext)s" --extract-audio --audio-format mp3'
alias ytvid='yt-dlp -ciw --format mp4 -o "%(title)s.%(ext)s"'
alias vpnip='curl ifconfig.co/city && curl ip.me'



# Mattio's config for the Zoomer Shell

# Enable colors and change prompt:
autoload -U colors && colors
#PS1="%B%{$fg[red]%}[%{$fg[yellow]%}%n%{$fg[green]%}@%{$fg[blue]%}%M %{$fg[magenta]%}%~%{$fg[red]%}]%{$reset_color%}$%b "

#Cool green
#PS1="%B%{$fg[green]%}[%{$fg[white]%}%n%{$fg[green]%}@%{$fg[grey]%}%M %{$fg[yellow]%}%~%{$fg[green]%}]%{$reset_color%}$%b "

# Christmas :)
PS1="%B%{$fg[magenta]%}[%{$fg[green]%}%n%{$fg[yellow]%}@%{$fg[red]%}%M %{$fg[blue]%}%~%{$fg[magenta]%}]%{$reset_color%}$%b "

# Minimal prompt
#PS1="%F{green}%B%~%b%f %F{grey}%BΣ%b "
# Bruh, sigma male meme
#PS1="%F{green}%B%~%b%f %F{black}%BΣ%b "

#PS1="%F{gray}%n% %F{green}@% %F{grey}%M"

# History in cache directory:
HISTSIZE=10000
SAVEHIST=10000
HISTFILE=~/.cache/zsh/history

### ARCHIVE EXTRACTION - stolen from dt
# usage: ex <file>
ex () {
  if [ -f "$1" ] ; then
    case $1 in
      *.tar.bz2)   tar xjf $1   ;;
      *.tar.gz)    tar xzf $1   ;;
      *.bz2)       bunzip2 $1   ;;
      *.rar)       unrar x $1   ;;
      *.gz)        gunzip $1    ;;
      *.tar)       tar xf $1    ;;
      *.tbz2)      tar xjf $1   ;;
      *.tgz)       tar xzf $1   ;;
      *.zip)       unzip $1     ;;
      *.Z)         uncompress $1;;
      *.7z)        7z x $1      ;;
      *.deb)       ar x $1      ;;
      *.tar.xz)    tar xf $1    ;;
      *.tar.zst)   unzstd $1    ;;
      *)           echo "'$1' cannot be extracted via ex()" ;;
    esac
  else
    echo "'$1' is not a valid file"
  fi
}

# Basic auto/tab complete:
autoload -U compinit
zstyle ':completion:*' menu select
zmodload zsh/complist
compinit
_comp_options+=(globdots)		# Include hidden files.

# vi mode
bindkey -v
export KEYTIMEOUT=1

# Use vim keys in tab complete menu:
bindkey -M menuselect 'h' vi-backward-char
bindkey -M menuselect 'k' vi-up-line-or-history
bindkey -M menuselect 'l' vi-forward-char
bindkey -M menuselect 'j' vi-down-line-or-history
bindkey -v '^?' backward-delete-char

# Change cursor shape for different vi modes.
function zle-keymap-select {
  if [[ ${KEYMAP} == vicmd ]] ||
     [[ $1 = 'block' ]]; then
    echo -ne '\e[1 q'
  elif [[ ${KEYMAP} == main ]] ||
       [[ ${KEYMAP} == viins ]] ||
       [[ ${KEYMAP} = '' ]] ||
       [[ $1 = 'beam' ]]; then
    echo -ne '\e[5 q'
  fi
}
zle -N zle-keymap-select
zle-line-init() {
    zle -K viins # initiate `vi insert` as keymap (can be removed if `bindkey -V` has been set elsewhere)
    echo -ne "\e[5 q"
}
zle -N zle-line-init
echo -ne '\e[5 q' # Use beam shape cursor on startup.
preexec() { echo -ne '\e[5 q' ;} # Use beam shape cursor for each new prompt.

# Use lf to switch directories and bind it to ctrl-o
lfcd () {
    tmp="$(mktemp)"
    lf -last-dir-path="$tmp" "$@"
    if [ -f "$tmp" ]; then
        dir="$(cat "$tmp")"
        rm -f "$tmp"
        [ -d "$dir" ] && [ "$dir" != "$(pwd)" ] && cd "$dir"
    fi
}
bindkey -s '^o' 'lfcd\n'

# Edit line in vim with ctrl-e:
autoload edit-command-line; zle -N edit-command-line
bindkey '^e' edit-command-line

#compinit -d $XDG_CACHE_HOME/zsh/zcompdump-$ZSH_VERSION

eval "$(starship init zsh)"
alias luamake=/home/mattio/.config/lua-language-server/3rd/luamake/luamake

# THIS GOES LAST, ALWAYS
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh 2>/dev/null
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh 2>/dev/null
