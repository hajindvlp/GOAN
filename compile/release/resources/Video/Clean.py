from PIL import ImageTk, Image

for i in range(900):
    iname = str(i)+"_.bmp"
    oname = str(i)+".bmp"
    img = Image.open(iname)
    newimg = img.convert(mode="P", palette=Image.ADAPTIVE, colors=256)
    newimg.save(oname)
    print(i)