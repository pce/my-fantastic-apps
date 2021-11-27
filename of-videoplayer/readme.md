## of-videoplayer 

Test-App for the big screen, to compile adjust `OF_ROOT` in config.make.

- `make && make RunRelease`


-  MacOS: to install OF, download a Zip the https://openframeworks.cc/download/ (ie. nightly build  `of_v20210803_osx_nightly.zip`), unzip (ie, anywhere above this repo) and point  `OF_ROOT` to that unzipped folder, ie. `/Users/user/my-projects/of_v20210803_osx_release`

- reduce filesize https://unix.stackexchange.com/questions/28803/how-can-i-reduce-a-videos-size-with-ffmpeg `ffmpeg -i ECBA_Technology\ in\ a\ nutshell_MPL_Subtitle_20210609.mp4 -b 800k idle.mp4`


Make a Video from single image: 
    
    ffmpeg -loop 1 -i tour_select.png -pix_fmt yuv420p -t 20 out.mp4
    cp out.mp4 ../videos/tour_select.mp4
