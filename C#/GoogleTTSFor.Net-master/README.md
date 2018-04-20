# GoogleTTSFor.Net
=============================================
       Google TTS script for C# .Net

This script makes use of Google's translate text to speech service
in order to render text to speech and play it back to the user.
It supports a variety of different languages.

This TTS service is 'unofficial' and not supported by Google,
it can be terminated at any point with no warning.
People looking for TTS solutions to base their projects/products on
should look for alternative, officially supported  services.

------------
Requirements
------------
.Net Framework 4.0
NAudio
Internet access in order to contact google and get the voice data.

------------
Installation
------------
Please use GoogleTTS.sln

-----
Usage
-----
Please try it. This is very simple app. 
--------
Examples
--------
-------------------
Supported Languages
-------------------
Afrikaans:          af
Albanian:           sq
Amharic:            am
Arabic:             ar
Armenian:           hy
Azerbaijani:        az
Basque:             eu
Belarusian:         be
Bengali:            bn
Bihari:             bh
Bosnian:            bs
Breton:             br
Bulgarian:          bg
Cambodian:          km
Catalan:            ca
Chinese Simplified: zh-CN
Chinese Traditional:zh-TW
Corsican:           co
Croatian:           hr
Czech:              cs
Danish:             da
Dutch:              nl
English:            en
Esperanto:          eo
Estonian:           et
Faroese:            fo
Filipino:           tl
Finnish:            fi
French:             fr
Frisian:            fy
Galician:           gl
Georgian:           ka
German:             de
Greek:              el
Guarani:            gn
Gujarati:           gu
Hausa:              ha
Hebrew:             iw
Hindi:              hi
Hungarian:          hu
Icelandic:          is
Indonesian:         id
Interlingua:        ia
Irish:              ga
Italian:            it
Japanese:           ja
Javanese:           jw
Kannada:            kn
Kazakh:             kk
Kinyarwanda:        rw
Kirundi:            rn
Korean:             ko
Kurdish:            ku
Kyrgyz:             ky
Laothian:           lo
Latin:              la
Latvian:            lv
Lingala:            ln
Lithuanian:         lt
Macedonian:         mk
Malagasy:           mg
Malay:              ms
Malayalam:          ml
Maltese:            mt
Maori:              mi
Marathi:            mr
Moldavian:          mo
Mongolian:          mn
Montenegrin:        sr-ME
Nepali:             ne
Norwegian:          no
Norwegian Nynorsk:  nn
Occitan:            oc
Oriya:              or
Oromo:              om
Pashto:             ps
Persian:            fa
Polish:             pl
Portuguese:         pt
Portuguese Brazil:  pt-BR
Portuguese Portugal:pt-PT
Punjabi:            pa
Quechua:            qu
Romanian:           ro
Romansh:            rm
Russian:            ru
Scots Gaelic:       gd
Serbian:            sr
Serbo-Croatian:     sh
Sesotho:            st
Shona:              sn
Sindhi:             sd
Sinhalese:          si
Slovak:             sk
Slovenian:          sl
Somali:             so
Spanish:            es
Sundanese:          su
Swahili:            sw
Swedish:            sv
Tajik:              tg
Tamil:              ta
Tatar:              tt
Telugu:             te
Thai:               th
Tigrinya:           ti
Tonga:              to
Turkish:            tr
Turkmen:            tk
Twi:                tw
Uighur:             ug
Ukrainian:          uk
Urdu:               ur
Uzbek:              uz
Vietnamese:         vi
Welsh:              cy
Xhosa:              xh
Yiddish:            yi
Yoruba:             yo
Zulu:               zu

-----------------------
Security Considerations
-----------------------
This script contacts Google servers in order to get voice data.
The script uses TLS to encrypt all the traffic between your pbx and these servers
so no 3rd party can eavesdrop your communication, but your data will be available
to Google under a not yet defined policy.

-------
License
-------
The GoogleTTS script for asterisk is distributed under the GNU General Public
License v2. See COPYING for details.
