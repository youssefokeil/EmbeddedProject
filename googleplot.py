import os
import gmplot
import pandas as pd

df = pd.read_csv('gps.csv')

lat = (df.iloc[:, 0]).tolist()
lon = (df.iloc[:, 1]).tolist()

# creating object googlemapplotter
mapobj = gmplot.GoogleMapPlotter(lat[0], lon[0], 17, apikey="AIzaSyDAWYxImCuC-VVPQFrNC8AYd7c0G16KDTQ")

# scatter points on the Google map

mapobj.scatter(lat, lon, size=20, color ="red")

# Plot method Draw a line in between given coordinates
mapobj.plot(lat, lon, 'cornflowerblue', edge_width=2.5)

mapobj.draw("mappath.html")
os.system("mappath.html")

#
# # Replace 'YOUR_API_KEY' with your actual API key
# gmap = gmplot.GoogleMapPlotter.from_geocode("AIzaSyCT4n3MQijJptsK3cVWkxMKjdWpNxzIv9Q")
#
# # Add a marker for San Francisco
# gmap.marker(37.7749, -122.4194, title="San Francisco")
#
# # Add a polygon (shape)
# lats = [37.773972, 37.774546, 37.773972]
# lngs = [-122.419806, -122.419006, -122.418206]
# gmap.polygon(lats, lngs, color="cornflowerblue")
#
# #gmap.plot(path_lats, path_lngs, "red", edge_width=3)
#
# # Save the map to an HTML file
# gmap.draw("mymap.html")
