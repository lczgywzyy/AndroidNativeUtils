package u.can.i.up.app;

import android.content.Context;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationManager;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends ActionBarActivity {

    static {
        System.loadLibrary("myjni");
    }
    private native String testString();
    private native int testInt();
    private native String sendSMS();
    private native String getLocation();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        Log.i("TEST_STR", testString());
//        Log.i("TEST_INT", "" + testInt());
//        Log.i("SEND_SMS", "" + sendSMS());
        Log.i("TEST_LOC", "" + getLocation());
        getMyLocation();
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        return id == R.id.action_settings || super.onOptionsItemSelected(item);
    }

    private void getMyLocation(){
        LocationManager manager = (LocationManager) getApplication().getBaseContext().getSystemService(Context.LOCATION_SERVICE);
        Location location = null;
        location = manager.getLastKnownLocation(LocationManager.NETWORK_PROVIDER);
        Log.i("经度", "" + location.getLongitude());
        Log.i("纬度", "" + location.getLatitude());
    }
}
