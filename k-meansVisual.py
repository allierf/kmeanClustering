import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns


plt.figure()
df = pd.read_table("output1.txt",delimiter=" ")

sns.scatterplot(x=df.x, y=df.y,
                hue=df.c,
                palette=sns.color_palette("hls", n_colors=2))

plt.figure()
plt.show()