package com.example.include.myapplication;

import android.app.Activity;
import android.content.Context;
import android.location.Address;
import android.location.Geocoder;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;

import java.io.IOException;
import java.util.List;
import java.util.Locale;

public class MyLocation {
    final Geocoder geocoder;
    LocationManager locationManager;
    Activity context;

    MyLocation(Activity context) {
        this.context = context;
        geocoder = new Geocoder(context, Locale.KOREA);

        locationManager = (LocationManager) context.getSystemService(Context.LOCATION_SERVICE);
        try {
            locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER);
            locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 1000, 0, new LocationListener() {
                @Override
                public void onLocationChanged(Location location) {

                }

                @Override
                public void onStatusChanged(String provider, int status, Bundle extras) {

                }

                @Override
                public void onProviderEnabled(String provider) {

                }

                @Override
                public void onProviderDisabled(String provider) {

                }
            });
        } catch (SecurityException e) {

        }
    }

    String getAddress() {
        try {
            List<Address> list = geocoder.getFromLocation(getLatitude(context), getLongtitude(context), 10);
            if (list.size() != 0) return "<<" + list.get(0).getAddressLine(0) + ">>\n";
        } catch (IOException e) {

        }
        return null;
    }

    public Double getLatitude(Activity context) {
        Location location = null;
        try {
            location = locationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
        } catch (SecurityException e) {
            e.printStackTrace();
        }
        return location.getLatitude();
    }
    public Double getLongtitude(Activity context) {
        Location location2 = null;
        try {
            location2= locationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
        } catch (SecurityException e) {
            e.printStackTrace();
        }
        return location2.getLongitude();
    }
}
