package Tojik.Mods.modmenu;

import android.content.Context;
import android.os.Build;
import android.util.Log;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Logcat {
    public static void Clear(Context context) {
        try {
            Runtime.getRuntime().exec("logcat -c");
            Toast.makeText(context, "Logcat cleared", Toast.LENGTH_LONG).show();
        } catch (IOException e) {
            Toast.makeText(context, "Error clearing logcat:", Toast.LENGTH_LONG).show();
            e.printStackTrace();
        }
    }

    public static void Save(Context context) {
        File path;
        try {
            Process process = Runtime.getRuntime().exec("logcat -d");
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            
            StringBuilder log = new StringBuilder();
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                log.append(line).append("\n");
            }
            
            if (Build.VERSION.SDK_INT >= 30) { // Android R+
                path = new File("/storage/emulated/0/Documents/");
            } else {
                path = new File(context.getExternalFilesDir(null), "Mod Menu");
            }
            
            if (!path.exists()) {
                path.mkdirs();
            }
            
            File file = new File(path, "Mod_Menu_" + context.getPackageName() + ".txt");
            
            try (BufferedWriter buf = new BufferedWriter(new FileWriter(file))) {
                buf.write(log.toString());
            }
            
            Toast.makeText(context, "Logcat saved successfully to: " + file.toString(), Toast.LENGTH_LONG).show();
        } catch (IOException e) {
            Toast.makeText(context, "Error saving logcat to file: " + Log.getStackTraceString(e), Toast.LENGTH_LONG).show();
            e.printStackTrace();
        }
    }
}
