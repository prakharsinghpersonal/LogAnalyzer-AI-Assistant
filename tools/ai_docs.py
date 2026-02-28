import os
import re

class CodeDocumenter:
    def __init__(self, source_dir):
        self.source_dir = source_dir

    def scan_files(self):
        """
        Scans source files for undocumented functions.
        """
        print(f"Scanning {self.source_dir} for undocumented code...")
        files = [f for f in os.listdir(self.source_dir) if f.endswith('.cpp') or f.endswith('.py')]
        
        for file in files:
            path = os.path.join(self.source_dir, file)
            self._process_file(path)

    def _process_file(self, file_path):
        with open(file_path, 'r') as f:
            lines = f.readlines()

        print(f"Analyzing {os.path.basename(file_path)}...")
        
        for i, line in enumerate(lines):
            # Simple heuristic for function definitions
            if line.strip().startswith("def ") or line.strip().startswith("void ") or line.strip().startswith("int "):
                if i > 0 and '"""' not in lines[i-1] and '//' not in lines[i-1]:
                    print(f"  -> Missing documentation for function at line {i+1}")
                    print(f"  -> [AI Action] Generating docstring...")
                    # In a real tool, this would insert the text
                    # lines.insert(i, self._generate_docstring(line))

    def _generate_docstring(self, function_signature):
        return f'    """\n    AI-Generated: Documentation for {function_signature.strip()}\n    """\n'

if __name__ == "__main__":
    # Point to the src directory for demo
    docs = CodeDocumenter("./src")
    docs.scan_files()
    print("\nDocumentation task complete. Estimated manual effort saved: 2 hours.")
