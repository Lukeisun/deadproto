import os
import subprocess

def compile_protos(proto_dir, output_dir, protoc_path):
    for root, _, files in os.walk(proto_dir):
        for file in files:
            if file.endswith('.proto'):
                proto_file = os.path.join(root, file)
                relative_path = os.path.relpath(root, proto_dir)
                output_path = os.path.join(output_dir, relative_path)
                
                if not os.path.exists(output_path):
                    os.makedirs(output_path)
                
                cmd = [
                    protoc_path,
                    f'--proto_path={proto_dir}',
                    f'--cpp_out={output_dir}',
                    proto_file
                ]
                
                try:
                    subprocess.run(cmd, check=True, capture_output=True, text=True)
                except subprocess.CalledProcessError as e:
                    print(f"Error compiling {proto_file}:")
                    print(e.stdout)
                    print(e.stderr)

if __name__ == "__main__":
    proto_dir = r"Deadlocked/Protobufs"
    output_dir = r"./gen"
    protoc_path = r"protoc"
    
    # if not os.path.exists(protoc_path):
    #     print(f"protoc not found at {protoc_path}")
    #     print("Please check the path and update it in the script.")
    # else:
    compile_protos(proto_dir, output_dir, protoc_path)
